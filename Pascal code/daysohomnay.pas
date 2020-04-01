uses crt;
var a:array[1..5000]of longint;
i,j,n,tg: longint;
begin
        read(n);
        for i := 1 to n do read(a[i]);
        for i:=1 to n-1 do
                for j:=i+1 to n do
                if a[j]<a[i] then
                begin
                        tg:=a[i];
                        a[i]:=a[j];
                        a[j]:=tg;
                end;
        for i:=1 to n do write(a[i],' ');

end.
