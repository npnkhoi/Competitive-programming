const fin='DABANH.INP';
    fon='DABANH.OUT';
var st1,st2:ansistring;
    i,s,n,t,z:longint;
    fi,fo:text;
procedure init;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,t);
end;
procedure thongbao;
begin
    if s>0 then writeln(fo,'10Tin ',i)
    else writeln(fo,'11Tin ',i)
end;
procedure main;
begin
    readln(fi,n);
    readln(fi,st1);
    readln(fi,st2);
    s:= 0;
    ////////////////////////////////
    for i:= 1 to n do
    begin
        if copy(st1,1,1)='Y' then inc(s);
        delete(st1,1,1);
        if copy(st2,1,1)='Y' then dec(s);
        delete(st2,1,1);
        if abs(s)>n-i then
        begin
            thongbao;
            exit;
        end;
    end;
    writeln(fo,'Chua xac dinh');
end;
procedure ending;
begin
    close(fi); close(fo);
end;
begin
    init;
    for z:= 1 to t do main;
    ending;
end.
