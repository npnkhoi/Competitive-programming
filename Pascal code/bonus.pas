uses math;
var a,s:array[0..1003,0..1003] of longint;
    n,k,i,j,kq:longint;
    fi,fo:text;
procedure start;
begin
    assign(fi,'bonus.inp'); reset(fi);
    assign(fo,'bonus.out'); rewrite(fo);
    readln(fi,n,k);
    for i:= 1 to n do
    for j:= 1 to n do read(fi,a[i,j]);
    //-----------------
    for i:= 0 to n do begin s[i,0]:= 0; s[0,i]:= 0; end;
    for i:= 1 to n do
    for j:= 1 to n do
    s[i,j]:= s[i-1,j]+s[i,j-1]+a[i,j]-s[i-1,j-1];
end;
procedure main;
begin
    kq:= 0;
    for i:= k to n do
    for j:= k to n do
    kq:= max(kq,s[i,j]+s[i-k,j-k]-s[i,j-k]-s[i-k,j]);
end;
begin
    start;
    main;
    writeln(fo,kq);
    close(fi); close(fo);
end.
