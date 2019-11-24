void setup()
{
   pinMode(D4, OUTPUT);//Define o LED Onboard como saida.
   digitalWrite(D4, 1);//Apaga o LED.
   delay(2000);//Espera 2 segundos para visualizarmos que o ESP foi iniciado.

   for (long x = 0; x < 20; x++)//Irá piscar o LED 10x com intervalo de 250mS
   {
      digitalWrite(D4, !digitalRead(D4));//Inverte o estado do LED.
      delayMicroseconds(250000);//Espera 250mS
      yield();//Efetua o feed do SW WDT.
   }

//Após piscar 10x sem erros, irá entrar no loop e o LED começara a piscar
// rapidamente indicando que não ocorreu erros.

//Este código efetua o feed do SW WDT, então logo após as 10 piscadas,
// começara a piscar rapidamente pois entrou no loop.
}

void loop()
{
   digitalWrite(D4, !digitalRead(D4));
   delay(50);
}
