#include "Connection.h"


Connection::Connection(int port, sf::IPAddress IP)
{
	client = new Client();
	if(Connect(IP, port))
	{
		
	}
}


Connection::~Connection(void)
{
}

void Connection::Run(void)
{
	//while(true)
	{
		Receive();

<<<<<<< HEAD
		//sf::sleep(sf::milliseconds(10));
=======
		Sleep(10);
>>>>>>> 3e2d1d23fd7a70df773ec0d22345bb1ca4eedc82
	}
}

bool Connection::Connect(sf::IPAddress ip, int port)
{
	if(client->socket.Connect(port, ip, 5) == sf::Socket::Done)
	{
		client->socket.SetBlocking(false);
		std::cout << "Connected to " << ip << " : " << port << std::endl;
		return(true);
	}
	else
	{
		std::cout << "Error connecting to " << ip << " : " << port << std::endl;
		return(false);
	}
}

void Connection::Receive()
{
	if(client->socket.IsValid())
	{
		sf::Packet *received = new sf::Packet();
		sf::Socket::Status status = client->socket.Receive(*received);
		if (status == sf::Socket::Done)
		{
			globalMutex.Lock();
			packets.push(received);
			globalMutex.Unlock();
		}
		else if(status == sf::Socket::Disconnected)
		{
			//Socket is disconnected, cout will spam >.<
		}
	}
}