# READ ME AQUAMARINE - GLOBAL SOLUTION
 
---
 
# Coleta Automática de Amostras de Água
 
Este projeto utiliza um Arduino para automatizar a coleta de amostras de água, monitorando continuamente o pH e a temperatura. As leituras são exibidas em um display LCD e as amostras são coletadas automaticamente a cada intervalo de tempo especificado.
 
## Componentes Utilizados
 
- Arduino Uno
- Display LCD (16x2) com interface paralela
- Sensor de pH
- Sensor de temperatura TMP36
- Motores DC
- Relés
- Protoboard
- Potenciômetro
- Fonte de alimentação (9V)
 
## Conexões
 
### Pinos do Arduino
 
- **Motores DC**: 13, 12, 11, 10, 9
- **Sensor de temperatura TMP36**: A1
- **Sensor de pH**: A0
- **LCD**: 8 (RS), 7 (E), 6 (D4), 5 (D5), 4 (D6), 3 (D7)
 
### Diagrama de Circuito
 
O circuito inclui as conexões de todos os componentes mencionados acima. Certifique-se de que todas as conexões estejam firmes e corretas conforme o diagrama fornecido.
 
### Explicação do Código
 
1. **Bibliotecas e Pinos**: O código começa com a inclusão da biblioteca `LiquidCrystal` e a definição dos pinos utilizados para os motores, sensores e LCD.
2. **Intervalos de Tempo**: Define os intervalos para atualização de leituras dos sensores, início da coleta e duração de ativação dos motores.
3. **Variáveis de Controle**: Utilizadas para controlar o tempo e o estado do sistema de coleta.
4. **Função `initializePins`**: Configura os pinos dos motores como saídas e garante que todos estejam inicialmente desligados.
5. **Função `initializeLCD`**: Inicializa o LCD e exibe uma mensagem inicial.
6. **Função `readTemperature`**: Lê a temperatura do sensor TMP36 e converte o valor para Celsius.
7. **Função `readPH`**: Lê o valor do potenciômetro e converte para a escala de pH.
8. **Função `updateDisplay`**: Atualiza o display LCD com as leituras de temperatura e pH.
9. **Função `activateMotor`**: Ativa um motor por um tempo especificado e depois o desliga.
10. **Função `setup`**: Inicializa os pinos, o LCD e configura o tempo inicial de coleta.
11. **Função `updateSensors`**: Atualiza as leituras dos sensores se o intervalo de tempo especificado tiver passado.
12. **Função `startCollection`**: Inicia a coleta de dados se o intervalo de tempo especificado tiver passado e não houver uma coleta em andamento.
13. **Função `collectData`**: Controla a ativação dos motores para a coleta de amostras. Exibe uma mensagem no LCD durante a coleta e ao finalizar.
14. **Função `loop`**: Função principal que roda continuamente, chamando as funções para atualizar as leituras dos sensores, iniciar a coleta e controlar a coleta de dados.
 
## Como Utilizar
 
1. **Montagem do Circuito**: Monte o circuito conforme descrito na seção de conexões e no diagrama de circuito fornecido.
2. **Carregamento do Código**: Carregue o código no Arduino utilizando a IDE do Arduino.
3. **Iniciar o Sistema**: Conecte a alimentação e observe o LCD inicializando e exibindo as leituras de temperatura e pH.
4. **Coleta Automática**: O sistema coletará amostras automaticamente a cada intervalo de 10 segundos, ativando cada motor sequencialmente por 5 segundos.
 
## Observações
 
- Certifique-se de que todas as conexões estejam corretas e firmes.
- Verifique a alimentação dos componentes, especialmente dos motores e relés.
- Ajuste os intervalos de tempo conforme necessário para a sua aplicação específica.
 
Este documento README detalha o funcionamento e a utilização do projeto de coleta automática de amostras de água, facilitando a replicação e o entendimento do sistema.
