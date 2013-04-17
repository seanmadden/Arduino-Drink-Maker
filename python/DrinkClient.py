# Echo client program
import socket
import json

HOST = '10.0.0.66'    # The remote host
PORT = 8771           # The same port as used by the server.

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.connect((HOST, PORT))

#tell the arduino how to make a rum and coke.
j = json.dumps({'ing0': 'rum', 'ing1': 'cola'})
print j

s.sendall(j)
#data = s.recv(1024)
s.close()
#print 'Received', repr(data)