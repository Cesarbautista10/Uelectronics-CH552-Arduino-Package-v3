// ================================================== =====================================
// Contenedor IDE de Arduino para ch55xduino
// ================================================== =====================================
//
// Instrucciones de compilación para el IDE de Arduino:
//----------------------------------------------------
// - Asegúrate de haber instalado ch55xduino: https://github.com/DeqingSun/ch55xduino
// - Copie los archivos .ino y .c, así como la carpeta /src, juntos en una sola carpeta
// y asígnale el nombre del archivo .ino. Abra el archivo .ino en el IDE de Arduino. Ir a
// "Herramientas -> Placa -> Placas CH55x -> Placa CH552". En "Herramientas", seleccione la
// siguientes opciones:
// - Fuente de reloj: 16 MHz (interno)
// - Método de carga: USB
// - Configuración USB: CÓDIGO DE USUARIO /w 266B USB RAM
// - Presiona el botón BOOT en la placa y mantenlo presionado mientras la conectas vía USB
// con tu PC.
// - Haga clic en "Cargar" inmediatamente después.


#ifndef USER_USB_RAM
#error "This firmware needs to be compiled with a USER USB setting"
#endif

unsigned char _sdcc_external_startup (void) __nonbanked {
  return 0;
}
