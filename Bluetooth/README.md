PNG-Arduino-Framework - Versão Beta 0.1
=====================

Framework com objetivo de facilitar o desenvolvimento de projetos com Arduino
Para suporte no bluetooth com conexão ao Android, veja: https://github.com/aron-bordin/Android-with-Arduino-Bluetooth

## Como instalar

Baixe os arquivos em https://github.com/ProgrammersOfNewGeneration/PNG-Arduino-Framework/archive/master.zip

Copie todos arquivos .cpp e .h na pasta de cada componente para a mesma pasta de seu arquivo .ino. 

## Como usar

No topo de seu arquivo .ino, adicione a linha
```c++
	#include "bluetooth.h"
```

Crie o objeto bluetooth:

```c++
	Bluetooth *blue = new Bluetooth();
```

No **void setup()**, adicione para configurar e conectar via bluetooth:
```c++
	blue->configuraBluetooth();
```
Agora, adicione os métodos desejados no **void loop()**, como enviar e receber mensagens, por exemplo:
```c++
	String msg = blue->Ler(); // recebe uma mensagem via Bluetooth
	blue->Enviar("Enviando uma mensagem por bluetooth");
```

## Comandos disponíveis

**int getrxPin();**  - Retorna o valor do pino RX

**void setrxPin(int rx);**  - Seta o valor do pino RX

**int gettxPin();**  - Retorna o valor do pino TX

**void settxPin(int tx);**  - Seta o valor do pino TX

**void configuraBluetooth();** - Inicia o módulo Bluetooth, configurando e conectando

**Bluetooth();** - Cria o objeto Bluetooth

**Bluetooth(int r, int t);** - Cria o objeto Bluetooth, com RX e TX

**String Ler();** - Recebe uma mensagem

**void Enviar(char c[]);** - Envia uma mensagem


## Sobre

Framework para desenvolvimento facilitar o desenvolvimento de projetos com a plataforma Arduino. Foi desenvolvido objetivo proporcionar à FEB e ao CTI na Unesp de Bauru, pesquisas nas áreas de robótica com o microcontrolador Arduino e análise de imagens com Android. 

A Framework está em versão beta, com suporte a:
* Bluetooth
* Motor
* Sensores de luz
* Servo motores
* Ultrassom