const fin='KNJI.INP';
    fon='KNJI.OUT';
    nmax=300007;
var s,a:array[0..300000] of longint;
    n,i,x,dem:longint;
    fi,fo:text;
procedure input;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,n);
    for i:= 1 to n do readln(fi,s[i]);
end;
procedure main;
begin
        x:= n; dem:= 0;
        for i:= n downto 1 do
        if s[i]=x then dec(x) else inc(dem);
end;
procedure ending;
begin
    writeln(fo,dem);
    close(fi); close(fo);
end;
begin
    input;
    main;
    ending;
end.