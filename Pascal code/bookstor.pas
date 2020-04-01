var n,i,x:longint;
    s:int64;
    a:array[0..100003] of longint;
    fi,fo:text;
procedure start;
begin
    assign(fi,'bookstor.inp'); reset(fi);
    assign(fo,'bookstor.out'); rewrite(fo);
    readln(fi,n);
    for i:= 1 to n do readln(fi,a[i]);
end;
procedure sort(l,r:longint);
var i,j,mid,tmp:longint;
begin
    i:= l; j:= r; mid:= a[(l+r)div 2];
    repeat
        while a[i]<mid do inc(i);
        while a[j]>mid do dec(j);
        if i<=j then
        begin
            tmp:= a[i]; a[i]:= a[j]; a[j]:= tmp;
            inc(i); dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
end;
procedure main;
begin
    s:= 0;
    for i:= 1 to n do s:= s+a[i];
    x:= (n+1) mod 3;
    for i:= 1 to n do if i mod 3 = x then s:= s-a[i];
end;
begin
    start;
    sort(1,n);
    main;
    writeln(fo,s);
    close(fi); close(fo);
end.