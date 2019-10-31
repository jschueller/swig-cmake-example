import openturns as ot

mesh = ot.Mesh(5)

for v in mesh:
    print(v)

print('OK')


mesh.exportToTXT('/tmp/mesh.txt')
