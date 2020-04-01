const fin='';
    fon='';
var c:array[0..253,0..253] of longint;
    free:array[0..253] of boolean;
    mark:array[0..253] of longint;
    adj,a,b:array[0..62503] of longint;
    n,m,i,j,u,v,count:longint;
    fi,fo:text;
procedure start;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,n,m);
    for i:= 1 to n do free[i]:= true;

    for i:= 1 to m do readln(fi,a[i],b[i]);
end;
procedure trans;
begin
    for i:= 0 to n do mark[i]:= 0;
    for i:= 1 to m do
    begin
        inc(mark[a[i]]); inc(mark[b[i]]);
    end;
    for i:= 1 to n do mark[i]:= mark[i-1]+mark[i];
    for i:= 1 to m do
    begin
        adj[mark[a[i]]]:= b[i];
        adj[mark[b[i]]]:= a[i];
        dec(mark[a[i]]);
        dec(mark[b[i]]);
    end;
end;
procedure visit(u:longint);
var v:longint;
begin
    free[u]:= false;
    for v:= mark[u]+1 to mark[u+1] do if (free[adj[v]]) then visit(adj[v]);
end;
procedure finish;
begin
    count:=0;
    for i:= 1 to n do if free[i] then
        begin
            inc(count);
            writeln(fo,i);
        end;
    if count=0 then writeln(fo,0);
    close(fi); close(fo);
end;
begin
    start;
    trans;
    visit(1);
    finish;
end.
