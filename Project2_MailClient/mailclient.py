from socket import *
import ssl
import base64

msg = "\r\n I love computer networks!"
endmsg = "\r\n.\r\n"

sender = ""
reciever = ""
# Choose a mail server (e.g. Google mail server) and call it mailserver

mailserver = ""
serverPort = 25

# Create socket called clientSocket and establish a TCP connection with mailserver


clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((mailserver,serverPort))

recv = clientSocket.recv(1024).decode()
print(recv)
if recv[:3] != '220':
	print('220 reply not received from server.')

# Send HELO command and print server response.

heloCommand = 'HELO Alice\r\n'
clientSocket.send(heloCommand.encode())
recv1 = clientSocket.recv(1024).decode()
print(recv1)
if recv1[:3] != '250':
	print('250 reply not received from server.')

# Send MAIL FROM command and print server response.

mailFromCommand = 'MAIL FROM: <' + sender + '> \r\n'
clientSocket.send(mailFromCommand.encode())
recv2 = clientSocket.recv(1024).decode()
print(recv2)
if recv2[:3] != '250':
	print ('250 reply not received from server.')

# Send RCPT TO command and print server response.

rcptToCommand = 'RCPT TO: <' + reciever + '> \r\n'
clientSocket.send(rcptToCommand.encode())
recv3 = clientSocket.recv(1024).decode()
print(recv3)
if recv3[:3] != '250':
	print ('250 reply not received from server.')

# Send DATA command and print server response.

dataCommand = 'DATA\r\n'
clientSocket.send(dataCommand.encode())
recv4 = clientSocket.recv(1024).decode()
print(recv4)
if recv4[:3] != '250':
	print ('250 reply not received from server.')

# Send message data.
clientSocket.send(msg.encode())

# Message ends with a single period.

clientSocket.send(endmsg.encode())

# Send QUIT command and get server response.

quitCommand = 'QUIT\r\n'
clientSocket.send(quitCommand.encode())
recv5 = clientSocket.recv(1024).decode()
print(recv5)
if recv5[:3] != '250':
	print ('250 reply not received from server.')
	
clientSocket.close()
