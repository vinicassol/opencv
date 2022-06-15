#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void CarregarImagem(string nomeImagem, string titulo)
{

    Mat imagem; // variavel do tipo matriz, que vai guardar a imagem
    Mat imagemPqna;
    Mat novoTamanho;
    Mat orelhaRecortada;
    Mat tonsDeCinza;
    Mat rgbTrocado;
    Mat arestas;
    Mat arestasCinza;

    imagem = imread(nomeImagem); //leitura do arquivo de imagem e armazenando os dados na matriz

    cout << "\n\nTAMANHO DA IMAGEM: " << imagem.size() << endl << endl;
    resize(imagem, imagemPqna, Size(), 0.5, 0.5);
    resize(imagem, novoTamanho, Size(900, 1100));


    // Para recortar eu preciso definir um retangulo do tamanhoa que eu quero
    Rect areaRecorte(200, 200, 120 , 120);
    orelhaRecortada = imagem(areaRecorte);

    //Conversão para tons de cinza
    cvtColor(imagemPqna, tonsDeCinza, COLOR_BGR2GRAY); // BGR representa RGB
    cvtColor(imagemPqna, rgbTrocado, COLOR_RGB2GRAY);

    //Contornos / Arestas
    Canny(imagemPqna, arestas, 20, 80);
    Canny(tonsDeCinza, arestasCinza, 20, 80);


    imshow(titulo, imagem); // original
    imshow("Scale", imagemPqna);
    imshow("Novo Tamanho", novoTamanho);
    imshow("Orelha Recortada", orelhaRecortada);
    imshow("Tons de Cinza", tonsDeCinza);
    imshow("RGB 2 Gray - Trocado", rgbTrocado);
    imshow("Canny - Color", arestas);
    imshow("Canny - Cinza", arestasCinza);


    imwrite("ArestasCinzas.png",arestasCinza);


}
int main() {
    cout << "Hello, World!" << endl;
    cout << "OpenCV version is " << CV_VERSION << endl;

    CarregarImagem("mario.png", "Super Mario");
   // CarregarImagem("luigi.png", "Luigi");

    waitKey(0);

    return 0;

}
