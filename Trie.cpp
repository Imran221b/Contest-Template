f(" %s",s);
 
        insert(s,strlen(s));
    }
 
    cin >> n; //number of words to search
 
    rep(i,n) {
 
        scanf(" %s",s);
        cout << search(s,strlen(s)) << endl;
    }
 
    del(root);
 
    return 0;
}
