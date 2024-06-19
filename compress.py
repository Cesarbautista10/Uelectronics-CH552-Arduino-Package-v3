#!/usr/bin/env python3
# compress.py

"""
Descripción: Genera un archivo comprimido tar.bz2 de una carpeta y guarda información del archivo comprimido en un archivo de texto.
Autor: Cesar
Fecha de creación: 01/04/2024
Fecha de modificación:
Versión: 1.0
Dependencias: tarfile, os, hashlib, datetime
"""

import tarfile
import os
import hashlib
import datetime

def compress_folder(folder_path, output_filename):
    with tarfile.open(output_filename, "w:bz2") as tar:
        tar.add(folder_path, arcname=os.path.basename(folder_path))

def get_file_info(file_path):
    file_size = os.path.getsize(file_path)
    file_type = file_path.split('.')[-1]
    return file_size, file_type

def calculate_sha256(file_path):
    sha256_hash = hashlib.sha256()
    with open(file_path, "rb") as f:
        for byte_block in iter(lambda: f.read(4096), b""):
            sha256_hash.update(byte_block)
    return sha256_hash.hexdigest()

def save_to_txt(filename, file_name, file_info, sha256_hash):
    with open(filename, "w") as file:
        file.write(f"Nombre del archivo comprimido: {file_name}\n")
        file.write("Datos del archivo comprimido:\n")
        file.write(f"Tamaño del archivo: {file_info[0]} bytes\n")
        file.write(f"Tipo de archivo: {file_info[1]}\n")
        file.write(f"SHA256 del archivo: {sha256_hash}\n")

if __name__ == "__main__":
    # Nombre de la carpeta que quieres comprimir
    folder_to_compress = "./ch55x"
    
    # Nombre del archivo de salida con la fecha actual
    output_filename = f"duino_version_{datetime.datetime.now().strftime('%Y-%m-%d')}.tar.bz2"
    
    # Comprimir la carpeta
    compress_folder(folder_to_compress, output_filename)
    
    # Obtener información del archivo comprimido
    file_info = get_file_info(output_filename)
    
    # Calcular el hash SHA256 del archivo comprimido
    sha256_hash = calculate_sha256(output_filename)
    
    # Guardar información en un archivo de texto
    save_to_txt("file_info.txt", output_filename, file_info, sha256_hash)
    
    print("Información del archivo comprimido guardada en file_info.txt")
