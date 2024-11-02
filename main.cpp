#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>   // 包含 pow  sqrt函數的標頭檔(算次方 平方根) 
#include <iomanip>  // 包含控制輸出格式的標頭檔

using namespace std;

 //算平均值 
double average(const vector<double> & data){
	double sum = 0.0;
	double num = 0.0;
	
	for(int y = 0; y < data.size(); y++){
		num = data[y];
		sum += num;
	}
	
	if(data.size() == 0){
		return 0.0;
	}
	
	return sum / data.size();
}


 //算標準差 
double sigma(const vector<double> & data){
	
    double deviation = 0.0;
    double variation = 0.0;

    for (int x = 0; x < data.size(); x++){
    	deviation = data[x] - average(data);
    	variation += (deviation*deviation);
	}
	
		if(data.size() == 0){
		return 0.0;
	}
	
	return sqrt(variation / data.size() );
	
}

int main()
{
	int numData;
    vector<double> data;
    
    
    cout << "How many data: ";
    cin >> numData;
    
    
	
	for (int i = 0; i < numData; ++i) {
	    float value;
        cout << "please enter " << i+1 << " data: ";
        cin >> value;
        data.push_back(value);
    }
    cout << fixed << setprecision(3);
    cout<< "average"<< average(data) <<endl;
    cout<< "sigma"<< sigma(data) <<endl;
	
	system("pause");
    return 0;
 } 