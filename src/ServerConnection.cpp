#include "ServerConnection.h"


ServerConnection::ServerConnection(int port)
{
	maxClients = 10;
	s.SetBlocking(false);
	pingTimeout.Reset();
	if(!s.Listen(port))
	{
		std::cout << "Failed to bind to port " << port << ", maybe you already have a server listening on this port?" << std::endl;
	}
	else
		std::cout << "Server listening to port " << port << std::endl;
}


ServerConnection::~ServerConnection(void)
{
}

void ServerConnection::Run(void)
{
	while(true)
	{
		Accept();
		Receive();

		float ElapsedTime = pingTimeout.GetElapsedTime();
		if(ElapsedTime > 1)
		{
			pingTimeout.Reset();
			PingClients();
		}
		Sleep(10);
	}
}

void ServerConnection::PingClients(void)
{
	for(int i = 0; i < maxClients; i++) 
	{
		sf::SocketTCP client = clients.find(i)->second;
		if(clients.find(i) != clients.end())
		{
			sf::Packet send;
			sf::Int16 ping = 1;
			send << ping;
			client.Send(send);
		}
	}
}

void ServerConnection::Accept()
{
	sf::IPAddress clientAddress;
	sf::SocketTCP client;
	sf::Socket::Status status = s.Accept(client, &clientAddress);
	if (status == sf::Socket::Done)
	{
		for(int i = 0; i < maxClients; i++) 
		{
			if(clients.find(i) == clients.end())
			{
				client.SetBlocking(false);
				clients.insert(std::pair<int, sf::SocketTCP>(i, client));
				std::cout << clientAddress << " connected on socket " << i << std::endl;
				if(i >= maxClients-1)
				{
					KickClient(i, "Server full");
					std::cout << "Server full! This is not good! " << clients.size() << " players connected. " << std::endl;
				}
				break;
			}

		}
	}
	else
	{
		switch(status)
		{
		case sf::Socket::Status::Disconnected:
			std::cout << "Error: Could not accept socket: Socket disconnected" << std::endl;
			break;
		case sf::Socket::Status::Error:
			std::cout << "Error: Could not accept socket: Random error" << std::endl;
			break;
		case sf::Socket::Status::NotReady:
			//std::cout << "NotReady" << std::endl;
			break;
		}
	}
}

void ServerConnection::Receive()
{
	for(int i = 0; i < maxClients; i++) 
	{
		if(clients.find(i) != clients.end())
		{
			sf::SocketTCP client = clients.find(i)->second;
			if(client.IsValid())
			{
				sf::Packet *received = new sf::Packet();
				sf::Socket::Status status = client.Receive(*received);
				packets.push(received);
				if (status == sf::Socket::Done && received->GetDataSize() > 4)
				{
					// Extract the message and display it
					std::cout << "Client " << i << " says: " << "" << " name: " << "" << " with a size of " << received->GetDataSize() << std::endl;
				}
				else if(status == sf::Socket::Disconnected)
					KickClient(i, "Disconnected");
				if(received->GetDataSize() <= 0)
					delete(received);
			}
			else
				KickClient(i, "Not valid socket");
		}
	}
}

void ServerConnection::KickClient(int ID, std::string reason)
{
	auto client = clients.find(ID);
	if(client != clients.end())
	{
		const char *kickmsg = reason.c_str();
		sf::Packet send;
		send << 2 << kickmsg;
		client->second.Send(send);
		//Sleep(100);
		client->second.Close();
		clients.erase(ID);
		std::cout << "Kicked client " << ID << " - " << reason << std::endl;
	}
}
