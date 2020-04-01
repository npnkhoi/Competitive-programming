uses crt;
var a,b,tr:array[1..100] of longint;
        n,i,j,vt,vtmax,max:longint;
procedure input;
begin
        readln(n);
        for i:=1 to n do read(a[i]);
        readln;
end;
procedure main;
begin
        b[1]:= 1;
        tr[1]:= 0;
        for j:= 2 to n do
        begin
                vtmax:= 0; max:= 0;
                for i:= 1 to j-1 do
                if (a[i]<=a[j]) and (b[i]>max) then vtmax:= i;
                if vtmax>0 then
                        begin
                                b[j]:=b[vtmax]+1;
                                tr[j]:= vtmax;
                        end

                else
                        begin
                                b[j]:= 1;
                                tr[j]:= 0;
                        end;
        end;
end;
procedure output;
begin
        vt:= 1;
        for i:= 2 to n do if b[i]>b[vt] then vt:= i;
        writeln(b[vt]);
        repeat
                write(a[vt],' ');
                vt:= tr[vt];
        until tr[vt]=0;
        write(a[vt]);
end;
begin
        input;
        main;
        output;
end.
