nt min1=sum+1;
    for(auto i:power)
    {
        int diff=sum-min(power[i],armor);
        min1=min(min1,diff);
    }
    cout<<mi