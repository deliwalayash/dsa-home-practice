

if(m < n){
    return m+s-1;
}

int rem = m %n;

if(rem + s < n){
    return rem +s;
}

if(rem + s ==n){
    return n-1;
}

if(rem + s > n){
  return n-rem+1;
    
}
return 0;

}
