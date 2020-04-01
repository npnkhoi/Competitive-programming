const mo=trunc(1e7);
var n,m,i,j,kq:longint;
    a:array[0..201,0..201] of -1..3;
    f:array[0..201,0..201,0..3] of longint;
    fi:text;
procedure start;
begin
    //assign(fi,'hana2.inp'); reset(fi);
    readln(n,m);
    for i:= 1 to n do
    for j:= 1 to m do read(a[i,j]);
end;
procedure main;
begin
    f[1,1,0]:= 0;
    if a[1,2]<>-1 then f[1,2,0]:=1;
    if a[2,1]<>-1 then f[2,1,0]:=1;
    for j:= 3 to m do if a[1,j]=a[1,j-1] then f[1,j,0]:= f[1,j-1,0]
        else f[1,j,0]:= 0;
    for i:= 3 to n do if a[i,1]=a[i-1,j] then f[i,1,0]:= f[i-1,1,0]
        else f[i,1,0]:= 0;
    for i:= 2 to n do
    for j:= 2 to m do
    if a[i,j]=-1 then f[i,j,0]:= 0
    else  begin
        f[i,j,0]:= 0;
        if a[i-1,j]=a[i,j] then f[i,j,0]:= (f[i,j,0]+f[i-1,j,0]) mod mo;
        if a[i,j-1]=a[i,j] then f[i,j,0]:= (f[i,j,0]+f[i,j-1,0]) mod mo;
        //writeln(i,' ',j,' ',f[i,j,0]);
    end;
    f[n,m,0]:= (f[n,m-1,0]+f[n-1,m,0]) mod mo;
    //--------------------------------------------
    f[1,1,1]:= 0;
    for j:= 2 to m do
    if a[1,j]=-1 then f[1,j,1]:= 0
    else begin
        f[1,j,1]:= f[1,j-1,1];
        if (a[1,j-1]<>-1) and (a[1,j]<>a[1,j-1]) then f[1,j,1]:= (f[1,j,1]+f[1,j-1,0]) mod mo;
    end;
    for i:= 2 to n do
    if a[i,1]=-1 then f[i,1,1]:= 0
    else begin
        f[i,1,1]:= f[i-1,1,1];
        if (a[i,1]<>a[i-1,1]) and (a[i-1,1]<>-1) then f[i,1,1]:= (f[i,1,1]+f[i-1,1,0]) mod mo;
    end;
    for i:= 2 to n do
    for j:= 2 to m do
    if a[i,j]=-1 then f[i,j,1]:= 0
    else begin
        f[i,j,1]:= f[i-1,j,1]+f[i,j-1,1];
        if (a[i,j-1]<>-1) and (a[i,j-1]<>a[i,j]) then f[i,j,1]:= (f[i,j,1]+f[i,j-1,0]) mod mo;
        if (a[i-1,j]<>-1) and (a[i-1,j]<>a[i,j]) then f[i,j,1]:= (f[i,j,1]+f[i-1,j,0]) mod mo;
    end;
    f[n,m,1]:= (f[n-1,m,1]+f[n,m-1,1]) mod mo;
    //-----------------------------------------
    for j:= 1 to m do f[1,j,3]:= 0;
    for i:= 1 to n do f[i,1,3]:= 0;
    f[1,1,3]:= 1;
    for j:= 2 to m do if a[1,j]=-1 then f[1,j,3]:= 0 else f[1,j,3]:= f[1,j-1,3];
    for i:= 2 to n do if a[i,1]=-1 then f[i,1,3]:= 0 else f[i,1,3]:= f[i-1,1,3];
    for i:= 2 to n do
    for j:= 2 to m do
    if a[i,j]=-1 then f[i,j,3]:=0 else
        f[i,j,3]:= (f[i-1,j,3]+f[i,j-1,3]) mod mo;
    kq:= f[n,m,3]-f[n,m,0];
    if kq<0 then kq:= mo+kq;
end;
begin
    start;
    main;
    writeln(kq);
    {for i:= 1 to n do
    begin
    for j:= 1 to m do write(a[i,j]:3); writeln;
    end;
    writeln;

    for i:= 1 to n do
    begin
    for j:= 1 to m do write(f[i,j,0]:3); writeln;
    end;
    writeln;
    for i:= 1 to n do
    begin
    for j:= 1 to m do write(f[i,j,1]:3); writeln;
    end;
    writeln;
    for i:= 1 to n do
    begin
        for j:= 1 to m do write(f[i,j,3]:3); writeln;
    end;
    close(fi); }
end.