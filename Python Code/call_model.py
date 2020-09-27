from ctypes import CDLL

dll = 'C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/DLL Code - Copia/Model/Debug/Model.dll'

model = CDLL(dll)

print(type(model))
print(model.main)
pass
