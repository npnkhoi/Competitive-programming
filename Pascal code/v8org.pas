uses crt;
var c:array[1..10000,1..10000] of longint;
    deg,f:array[1..10000] of longint;
    n,k,i,j,u,v,count:longint;
    fi,fo:text;
procedure load;
var x:longint;
begin
        assign(fi,'v8org.inp'); reset(fi);
        readln(fi,k);
        readln(fi,n);
        fillchar(deg,sizeof(deg),0);
        fillchar(c,sizeof(c),0);
        for i:= 2 to n do
        begin
            read(fi,x);
            inc(deg[x]);
            c[x,deg[x]]:= i;
        end;

end;
function adj(a,b:longint):boolean;
var i: longint;
begin
    for i:= 1 to deg[a] do if c[a,i]=b then exit(true);
    exit(false);
end;
procedure dfs(u:longint);
var i:longint;
begin
    f[u]:= 1;
    for i:= 1 to deg[u] do
    if adj(u,c[u,i]) then
    begin
        dfs(c[u,i]);
        f[u]:=f[u]+f[c[u,i]];
    end;
    if f[u]>=k then
    begin
        f[u]:=0;
        inc(count);
    end;
end;
procedure import;
begin
    assign(fo,''); rewrite(fo);
    writeln(fo,count);
    close(fi); close(fo);
end;
begin
    load;
    count:= 0;
    dfs(1);
    import;
end.
