# Bypass Emulador - FreeFire
Funcional na Versão: 1.69.X
- Faça um bom aproveitamente!
- Já que a godsteam não cria código como dizem por ai
- Código desenvolvido por GodsTeam > Scott..
- Dizem que nos não cria nada mas se aproveitaram de um erro nosso por liberar nossa lib desprotegida e agora estão usando em sua gambiarra.
- Espero que a garena não faça uma correção e vocês façam um bom aproveitamente.
- Basta incluir a il2cpp.h no projeto de vocês

## Todos os créditos é da GodsTeam!
### Autor: Scxtt#0001
### Equipe: GodsTeam
Discord: [Discord Oficial - GodsTeam](https://discord.gg/YXmRxRDUXp)


## Como esse bypass de `Emulador` funciona?
+ Veja bem, apos nos ir até o local da address `[0x2D54EB4]` encontraremos a primeira informação, informando que nos somos um `EMULADOR` que no caso seria `GCloud_AnoSDK_AnoSDK__Ioctl(10, StringLiteral_28851);`, você deve se perguntar. Mas oque seria esse número 10?
+ Ele é uma "CONEXÃO" entre `libanogs.so` com a `libil2cpp.so` digamos que seria uma "QUERY" que são conectada uma a outra.. 
+ Ela está na il2cpp em `public enum AnoSDKIoctlCMD` veja abaixo

  ![image-eptHYhE](https://i.imgur.com/eptHYhE.png)
  
+ Veja que a "QUERY 10" é informando que "É EMULADOR" traduzido de "inglês" para português!

- `IsEmulator = 10`
- `StringLiteral_28851 = files_dir=/data/data/com.dts.freefireth/files|wait=1`

+ Entendendo a verificação

![image-EqUqPa1](https://i.imgur.com/EqUqPa1.png)

Bom, após ter reconhecido a query 10 como um emulador. Logo a baixo tem uma verificação se a string é `NULL` ou `EM BRANCO` que no caso seria `empty`
+ `if ( System_String__IsNullOrEmpty(v2) )`
+ Essa if é uma checagem se caso `GCloud_AnoSDK_AnoSDK__Ioctl(10, StringLiteral_28851)` não for `em branco -> (empty) ou null` eu serei um emulador
+ Vejamos que aqui se inicia a verificação, segue a img abaixo.

![image-C6hHzBZ](https://i.imgur.com/C6hHzBZ.png)

+ Simples né?
+ Mas agora oque devemos fazer para informar que não somos um emulador?
+ É bem simples, vamos construir nosso código..
+ Antes irei explicar uma coisa pra vocês sobre lógica do operador que iremos usar.
+ Neste caso iremos usar `!` na lógica essa exclamação é informando que seria um `"NÃO"` segue um exemplo abaixo
+ Vamos usar uma bool como exemplo.

```cpp
bool test = false;
if( !test ){
   retornando ela mesmo estando false
}
```

+ Eu não irei entrar em detalhe mas repare bem oque ela está fazendo :)
+ É dessa forma que estamos anulando a verificação do emulador em nosso bypass
+ Vamos ao código agora.
```cpp
System_Byte_array *ArrayDetectEmulator_ffano(System_String_o *id)
{
    const char* StringLiteral_25777 = "files_dir=/data/data/com.dts.freefireth/files|wait=1";
    const char* StringLiteral_25778 = "GetEmpty";
    System_String_o *EmulatorCheck = GCloud_AnoSDK_AnoSDK_Ioctl(10, CreateString(StringLiteral_25777));

    // veja aqui.. A lógica citada em cima da exclamação seria para informar que +
    // if ( !System_String_IsNullOrEmpty(EmulatorCheck) ) EmulatorCheck seria a StringLiteral_25778
    // simplesmente revertemos a verificação de "TRUE" para "FALSE" com a exclamação.
    
    if ( !System_String_IsNullOrEmpty(EmulatorCheck) )
        EmulatorCheck = CreateString(StringLiteral_25778);
    // então a if não iria fazer a checagem e logo iria informar que é um Empty = mobile

    return GCommon_Checker_SendToServer(EmulatorCheck, id);
}
```

## Como usar em Apk-Script?
+ armeabi-v7a

```cpp
Pattern          : 0A 00 A0 E3 92 96 DA EB 00 50 A0 E1 90 00 9F E5 
Address          : 0x2D54F00
Hex Modificação  : 00 F0 20 E3
Hex Restauração  : 0A 00 A0 E3 | não precisa utilizar a restauração..
```

+ arm64-v8a

```cpp
Hex Modificação  : 1F 20 03 D5
```

+ Lembrando, Ative nesta tela para funcionar

![image-unknown](https://media.discordapp.net/attachments/944537033706209290/946064937854320680/unknown.png)

+ Bypass ativado

![image-unknown](https://media.discordapp.net/attachments/944537033706209290/946065009480450108/unknown.png)

### Divirta-se!!!!
