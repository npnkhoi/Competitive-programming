
procedure start;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,n,m);
    for i:= 1 to n do
    for j:= 1 to n do c[i,j]:= 0;
    for i:= 1 to m do
    begin
        readln(fi,u,v);
        c[u,v]:= 1; c[v,u]:= 1;
    end;
    readln(fi,w);
    for i:= 1 to w do readln(fi,c[i],k[i],p[i]);

end;