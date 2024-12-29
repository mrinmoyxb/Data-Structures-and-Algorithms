int first = 10;
    int *p = &first;
    int **q = &p;
    cout<<"First: "<<first<<endl;
    int second = ++(**q);
    cout<<first<<endl;
    cout<<second<<endl;