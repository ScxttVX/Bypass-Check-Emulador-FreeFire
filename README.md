# Bypass Emulador - FreeFire
Funcional na Versão: 1.69.X
- Faça um bom aproveitamente!
- Já que a godsteam não cria código como dizem por ai
- Código desenvolvido por GodsTeam > Scott..
- Dizem que nos não cria nada mas se aproveitaram de um erro nosso por liberar nossa lib desprotegida e agora estão usando em sua gambiarra.
- Espero que a garena não faça uma correção e vocês façam um bom aproveitamente.
- Basta incluir a il2cpp.h no projeto de vocês

Criador do código: Scott / GodsTeam!
Discord: https://discord.gg/YXmRxRDUXp

## Como esse bypass de `Emulador` funciona?
+ Veja bem, apos nos ir até o local da address `[0x2D54EB4]` encontraremos a primeira informação, informando que nos somos um `EMULADOR` que no caso seria `GCloud_AnoSDK_AnoSDK__Ioctl(10, StringLiteral_28851);`, você deve se perguntar. Mas oque seria esse número 10?
+ Ele é uma "CONEXÃO" entre `libanogs.so` com a `libil2cpp.so` digamos que seria uma "QUERY" que são conectada uma a outra.. 
+ Ela está na il2cpp em `public enum AnoSDKIoctlCMD` veja abaixo
  ![image-eptHYhE](https://i.imgur.com/eptHYhE.png)
  
+ Veja que a "QUERY" é uma informação 
