// Abstract datatype

#include <iostream>
using namespace std;

void unsortedADT(int n){
    int arr[n];
    for (int i=0; i<n; i++){
        cout<<"Enter the element "<<i<<" to create an array: ";
        cin>>arr[i];

    }
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    int choice;
    int newElement;
    int pos;
    cout<<"-----List of operation you can perform on unsorted array-----"<<endl;
    cout<<"1. Inserting an element in the begining"<<endl;
    cout<<"2. Inserting an element in the middle"<<endl;
    cout<<"3. Inserting an element in the last"<<endl;
    cout<<"4. Delete an element from the array"<<endl;
    cin>>choice;
    switch(choice){
    
        // Inserting an element in the begining
        case 1: cout<<"Enter the new Element: ";
                cin>>newElement;
        for (int i=n; i>0; i--){
            arr[i]=arr[i-1];
        }
        arr[0]=newElement;
        n++;
        for (int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        break;
    
        // Inserting an element in the middle
        case 2:cout<<"Enter the new Element: ";
            cin>>newElement;
        cout<<"Enter the position where you want to insert the element: ";
                cin>>pos;
                for(int i=n; i>pos; i--){
                    arr[i]=arr[i-1];
                }
                arr[pos]=newElement;
                n++;
                for (int i=0; i<n; i++){
                    cout<<arr[i]<<" ";
                }
                // cout<<endl;
        break;
    
        // Inserting an element in the last
        case 3: cout<<"Enter the new Element: ";
                cin>>newElement;
        arr[n]=newElement;
        n++;
        for (int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        break; 

        // Delete an element from the array        
        case 4:cout<<"Enter the Element you want to delete: ";
        cin>>newElement;
        pos=-1;
        for(int i=0; i<n; i++){
            if (arr[i]==newElement){
                pos=i;
                break;
            }
        }
        if (pos==-1){
            cout<<"Element not found";
        }
        else{
            for (int i=pos; i<n-1; i++){
                arr[i]=arr[i+1];
            }
            n--;
        }
        for (int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        break; 
    }
}

// void inputElement(int n, int arr){

// }


int main() {
    unsortedADT(5);
    // inputElement(5, arr)
    return 0;
} 
