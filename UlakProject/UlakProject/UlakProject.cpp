// UlakProject.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include "Calculate.cpp"
#include <vector>
using namespace std;

int main()
{
	int graph[vertex][vertex] = { { 0, 3, 0, 7, 8 },
								{ 0, 0, 1, 4, 0 },
								{ 0, 0, 0, 0, 0 },
								{ 0, 0, 2, 0, 0 },
								{ 0, 0, 0, 3, 0 },
	};

	int graphBell[][3] = { { 0, 1, 3 },
						   { 0, 3, 7 },
						   { 0, 4, 8 },
						   { 1, 2, 1 },
						   { 1, 3, 4 },
						   { 3, 2, 2 },
						   { 4, 3,3 } };

	Calculate calculate;
	vector<int> resultBellman = calculate.bellmanFord(graphBell, 7, 0);
	vector<int> resultDijkstra = calculate.dijkstra(graph, 0);
	std::cout << "Bellman Ford Algorithm" << endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << 0 << "---->" << i << " \t\t  " << resultBellman[i] << endl;
	}

	std::cout << "Dijkstra Algorithm" << endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << 0 << "---->" << i << " \t\t  " << resultDijkstra[i] << endl;
	}
}


// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
