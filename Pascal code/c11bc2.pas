
const nmax=10003;
    fin=''; fon='';
var n,m,i,x,k,u,v,loop,count:longint;
    deg:array[0..nmax] of longint;
    c:array[0..nmax,0..nmax] of longint;
    group:array[0..nmax] of longint;
    fi,fo:text;
procedure push(v,u:longint);
begin
    inc(deg[u]);
    c[u,deg[u]]:= v;
end;
procedure start;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,n,m);
    for i:= 1 to n do deg[n]:= 0;
    for i:= 2 to n do
    begin
        readln(fi,x,k);
        if k<>2 then
        begin
            push(x,i);
            push(i,x);
        end;
    end;
end;
procedure visit(u:longint);
var v:longint;
begin
    group[u]:= count;
    for v:= 1 to deg[u] do
    if group[c[u,v]]=0 then visit(c[u,v]);
end;
procedure main;
begin
    for i:= 1 to n do group[i]:= 0;
    u:= 1; count:= 0;
    repeat
        while (u<=n) and (group[u]<>0) do inc(u);
        if u<=n then
        begin
            inc(count);
            visit(u);
        end;
    until u>n;

    for loop:= 1 to m do
    begin
        readln(fi,u,v);
        if group[u]<>group[v] then writeln(fo,'YES')
        else writeln(fo,'NO');
    end;
end;
begin
    start;
    main;
    close(fi); close(fo);
end.

