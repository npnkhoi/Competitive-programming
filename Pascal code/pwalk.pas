type bang= record u:longint; v:longint; c:longint; end;
var n,q,i,x,y:longint;
    e:array[0..1001] of bang;
    a:array[0..1001,0..1001] of longint;
    head,d:array[0..1001] of longint;
    free:array[0..1001] of boolean;
    adj:array[0..2002] of longint;
    fi:text;
procedure start;
begin
    assign(fi,''); reset(fi);
    readln(fi,n,q);
    for i:= 1 to n-1 do
    begin
        with e[i] do readln(fi,u,v,c);
        a[e[i].u,e[i].v]:= e[i].c;
        a[e[i].v,e[i].u]:= e[i].c;
    end;
end;
procedure build_ADJ;
begin
    for i:= 1 to n-1 do
    begin
        inc(head[e[i].u]); inc(head[e[i].v]);
    end;
    for i:= 2 to n do head[i]:= head[i]+head[i-1];
    head[n+1]:= 2*n-2;
    for i:= 1 to n do
    begin
        adj[head[e[i].u]]:= e[i].v;
        adj[head[e[i].v]]:= e[i].u;
        dec(head[e[i].u]);
        dec(head[e[i].v]);
    end;
end;
procedure visit(u:longint);
var i:longint;
begin
    free[u]:= false;
    for i:= head[u]+1 to head[u+1] do
    if free[adj[i]] then
    begin
        d[adj[i]]:= d[u]+a[u,adj[i]];
        visit(adj[i]);
    end;
end;
begin
    start;
    build_adj;
    for i:= 1 to q do
    begin
        readln(fi,x,y);
        d[x]:= 0;
        fillchar(free,sizeof(free),true);
        visit(x);
        writeln(d[y]);
    end;
    close(fi);
end.