
procedure start;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,s1);
    m:= length(s1);
    readln(fi,s2);
    n:= length(s2);
end;
procedure max_sub;
begin
    for i:= 0 to m do f[i,0]:= 0;
    for j:= 0 to n do f[0,j]:= 0;
    for i:= 1 to m do
    for j:= 1 to n do
    begin
        if s1[i]<>s2[j] then f[i,j]:= max(f[i,j-1],f[i-1,j])
            else
        f[i,j]:= f[i-1,j-1]+1;
    end;
end;
procedure trace;
begin
    tmp:= f[m,n];
    i:= m; j:= n;
    while f[i,j]<>0 do
    begin
        if s1[i]=s2[j] then
        begin
            pos1[tmp]:= i;
            pos2[tmp]:= j;
            dec(tmp);
            dec(i); dec(j);
        end
            else
        if f[i-1,j]>f[]
    end;
end;
procedure finish;
begin

end;
