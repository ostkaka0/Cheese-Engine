#include "ServerConnection.h"

ServerConnection::ServerConnection(int port)
{
	maxClients = 1024;
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
		Client* client = clients.find(i)->second;
		if(clients.find(i) != clients.end())
		{
			sf::Packet send;
			sf::Uint16 ping = 1;
			send << ping;
			client->socket.Send(send);
			client->pingClock.Reset();
		}
	}
}

void ServerConnection::Accept()
{
	Client* client = new Client();
	client->pingClock = sf::Clock();
	sf::Socket::Status status = s.Accept(client->socket, &client->IP);
	if (status == sf::Socket::Done)
	{
		for(int i = 0; i < maxClients; i++) 
		{
			if(clients.find(i) == clients.end())
			{
				client->socket.SetBlocking(false);
				client->ID = i;
				clients.insert(std::pair<int, Client*>(i, client));
				sf::Packet packet;
				sf::Uint16 clientid = ClientID;
				packet << clientid << i;
				client->socket.Send(packet); 
				
				std::cout << client->IP << " connected on socket " << i << std::endl;
				if(i >= maxClients-1)
				{
					KickClient(i, "Server full");
					std::cout << "Server full! This is not good! " << clients.size() << " players connected. " << std::endl;
				}
				break;
			}

		}
		//delete(client);
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
		delete(client);
	}
}

void ServerConnection::Receive()
{
	for(int i = 0; i < maxClients; i++) 
	{
		if(clients.find(i) != clients.end())
		{
			Client* client = clients.find(i)->second;
			if(client->socket.IsValid())
			{
				sf::Packet *received = new sf::Packet();
				sf::Socket::Status status = client->socket.Receive(*received);
				if (status == sf::Socket::Done)
				{
					globalMutex.Lock();
					packets.push(std::pair<sf::Packet*, Client*>(received, client));
					globalMutex.Unlock();
					// Extract the message and display it
					//std::cout << "Client " << i << " says: " << *received << " with a size of " << received->GetDataSize() << std::endl;
				}
				else if(status == sf::Socket::Disconnected)
					KickClient(i, "Disconnected");
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
		client->second->socket.Send(send);
		//Sleep(100);
		client->second->socket.Close();
		clients.erase(ID);
		std::cout << "Kicked client " << ID << " - " << reason << std::endl;
	}
}

void ServerConnection::Broadcast(sf::Packet packet)
{
	//std::cout << packet << std::endl;
	for(std::pair<int, Client*> pair : clients)
	{
		pair.second->socket.Send(packet);
	}
}
