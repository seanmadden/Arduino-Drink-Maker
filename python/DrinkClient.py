# Echo client program
import socket
import json

HOST = '10.0.0.66'    # The remote host
PORT = 8771           # The same port as used by the server.

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.connect((HOST, PORT))

j = json.dumps({'4': 5, '6': 7})
print j

s.sendall(j)
#data = s.recv(1024)
s.close()
#print 'Received', repr(data)