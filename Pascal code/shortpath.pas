var q:array[0..1000001] of longint;
    d:array[0..1001] of longint;
    free:array[0..1001] of boolean;
    c:array[0..1001,0..1001] of 0..1;
    fi,fo:text;
    n,m,t,i,j,l,r,u,v,s,tmp,loop:longint;
procedure open;
begin
    assign(fi,'shortpath.inp'); reset(fi);
    assign(fo,'shortpath.out'); rewrite(fo);
    readln(fi,t);
end;
procedure push(x:longint);
begin
    inc(r); q[r]:= x; free[x]:= false;
end;
function pop:longint;
begin
    inc(l);
    exit(q[l-1]);
end;
procedure start;
begin
    readln(fi,n,m);
    for i:= 1 to n do d[i]:= -1;
    for i:= 1 to n do free[i]:= true;
    for i:= 1 to n do
    for j:= 1 to n do c[i,j]:= 0;
    for i:= 1 to m do
    begin
        readln(fi,u,v); c[u,v]:= 1; c[v,u]:= 1;
    end;
    readln(fi,s);
end;
procedure main;
begin
    l:= 1; r:= 0; d[s]:= 0;
    push(s);
    repeat
        tmp:= pop;
        for i:= 1 to n do if (c[tmp,i]=1) and free[i] then
        begin
            push(i);
            d[i]:= d[tmp]+6;
        end;
    until l>r;
end;
procedure finish;
begin
    for i:= 1 to n do if i<>s then
    write(fo,d[i],' ');
    writeln(fo);
end;
begin
    open;
    for loop:= 1 to t do
    begin
    start;
    main;
    finish;
    end;
    close(fi); close(fo);
end.