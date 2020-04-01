uses math;
var fi,fo:text;
    n,g,i,k,t,new:longint;
    a,r:array[0..101] of byte;

procedure start;
begin
    assign(fi,'room.inp'); reset(fi);
    assign(fo,'room.out'); rewrite(fo);
    readln(fi,n,g);
    for i:= 1 to g do read(fi,a[i]);
end;
procedure main;
begin
    k:= 0;
    for i:= 1 to g do
    begin
        t:= a[i];
        while t>0 do
        begin
            inc(k); if k>n then k:= 1;
            new:= min(r[k]+t,2);
            t:= t-(new-r[k]);
            r[k]:= new;
        end;
    end;
end;
begin
    start;
    main;
    for i:= 1 to n do writeln(fo,r[i]);
    close(fi); close(fo);
end.
