# Echo client program
import socket

HOST = '10.0.0.66'    # The remote host
PORT = 8771           # The same port as used by the server.

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.connect((HOST, PORT))
#as this is gets stored in a char array, it's your responsibility to null terminate the string
s.sendall('OPEN123\0')
#data = s.recv(1024)
s.close()
#print 'Received', repr(data)