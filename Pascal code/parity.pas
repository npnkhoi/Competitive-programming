var a:array[1..100001] of longint;
    c:array[-100001..100001] of longint;
    n,i,s,kq:longint;
    fi,fo:text;
procedure load;
begin
    assign(fi,'parity.inp'); reset(fi);
    readln(fi,n);
    for i:= 1 to n do read(fi,a[i]);
end;
procedure main;
begin
    fillchar(c,sizeof(c),0); c[0]:= 1;
    s:= 0; kq:= 0;
    for i:= 1 to n do
    begin
        if a[i] mod 2 = 0 then inc(s) else dec(s);
        inc(kq,c[s]);
        inc(c[s]);
    end;
end;
procedure import;
begin
    assign(fo,'parity.out'); rewrite(fo);
    writeln(fo,kq);
    close(fi); close(fo);
end;
begin
    load;
    main;
    import;

end.
