# OpenCV Basics
Repositório para uso diático e, em constante atualização, desenvolvido por Vini Cassol

## Configuração Inicial
Para trabalhar com OPENCV, o primeiro passo diz respeito a configuração de um projeto que permita acessar às funcionalidades disponibilizadas pela biblioteca.
Neste exemplo, vamos configurar um projeto para trabalhar com C++ utilizando o Microsoft Visual Studio.

### Download

Para começar, é necessário acessar a página de [releases do OpenCV](https://opencv.org/releases/) e fazer o download da versão estável. 
Neste guia, usaremos a versão 4.5.5 para windows. Após fazer o download, ao executar o arquivo, você deve selecionar um diretório para onde iremos extrair os arquivos.

![image](https://user-images.githubusercontent.com/20646897/172218228-4973b7e1-8141-47f7-94b2-8bd348a49ac4.png)

Sim, os arquivos da OPENCV ocupam mais de 1GB :scream:

Após a extração, você deve encontrar a seguinte estrutura de diretórios:

![image](https://user-images.githubusercontent.com/20646897/172218704-3cc9be60-c113-48d8-bd6a-3f519fe1fbdb.png)

### Variavel de Ambiente

Após finalizarmos o processo de instalação, precisamos definir uma variável de ambiente para o OpenCV. 
Para isso, basta buscar por variáveis de ambientes no menu inicial e acessar as propriedades do sistema.

![image](https://user-images.githubusercontent.com/20646897/172222002-20c5b93e-264a-4465-9dfd-5beea9ce6279.png)

Em seguida, acessa as variáveis de ambiente e crie uma nova variável para OpenCV e adcione o seguinte caminho: ``C:\Libraries\opencv\build\x64\vc15\bin``. 

Confirme o endereço de instalação do seu computador

![image](https://user-images.githubusercontent.com/20646897/172224163-26cd1967-ce96-4aa0-852b-0dc939d9ce02.png)

É importante obervarmos que estas configurações precisam ser feitas apenas uma vez, a paritr deste ponto, podemos criar quantos projetos quisermos!

## Configuração do Projeto no VS
Com as configurações finalizadas, podemos criar um projeto utilizando C++ e Microsoft Visual Studio.
Ao iniciar o VS, podemos criar um projeto C++ vazio, para rodar no console:

![image](https://user-images.githubusercontent.com/20646897/172226326-4060e610-5462-416e-8ca4-0f067cb766f3.png)


Com o projeto criado, precisamos observar algumas configurações:
* Modo DEBUG x64
![image](https://user-images.githubusercontent.com/20646897/172239204-0a53d02a-d2fa-42a1-a36e-de2355f43d68.png)
* Acessar o menu Projeto --> Propriedades e, em seguida, configurar o projeto para utilizar as bibliotecas do OPENCV
   * No menu Diretórios VC++ adicione os diretórios de Inclusão (include) e Diretórios de Biblioteca (lib)
![image](https://user-images.githubusercontent.com/20646897/172242103-6ec3057b-ba1d-4f7c-b76b-6459310f7040.png)
   * Nas opções do Vinculador (Linker), em Entrada (Input) precisamos adicionar a DLL do OpenCV nos arquivos de dependências adicionais. Neste campo, adicionamos a DLL de Debug que, nesta versão se chama ``opencv_world455d.lib`` e pode ser encontrada no diretório ``opencv\build\x64\vc15\lib``
  ![image](https://user-images.githubusercontent.com/20646897/172244647-e83bd50c-4d95-4c8f-bf42-b882710ad142.png)
  * Em propriedades de configuração --> depuração, setar em Ambiente, o caminho do diretório de DLLs. Adicione o caminho do diretório ``\opencv\build\x64\vc15\bin`` de acordo com a instalação em seu computador.
   ![image](https://user-images.githubusercontent.com/20646897/172255682-ca1e1f1b-cdba-4a3e-8d6e-dd0036a0986a.png)



## Hello World
O código a seguir, pode ser executado para verificar a configuração foi finalizada com sucesso:

<pre><code>
  #include < iostream >
  #include < opencv2/opencv.hpp >
  using namespace std;
  using namespace cv;
  
  int main() 
  {
    cout << "Hello, World!" << endl;
    cout << "OpenCV version is " << CV_VERSION << endl;
    return 0;
  }
</code></pre>

Se tudo correr bem, você deve visualizar a seguinte mensagem no console:
![image](https://user-images.githubusercontent.com/20646897/172251625-33c3df5f-78b4-4d3f-bbd1-4133911cd099.png)

