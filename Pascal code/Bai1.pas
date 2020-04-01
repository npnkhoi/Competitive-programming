uses crt;
var     a: array [1..300] of longint;
        n, i, dem, tong, vt: longint;
begin
        readln(n);
        for i := 1 to n do read(a[i]);
        // Cau a:
        writeln('Day vua nhap: ');
        for i := 1 to n do write(a[i],' ');
        writeln;
        // Cau b:
        dem := 0; tong := 0;
        for i := 1 to n do
                if a[i] mod 2 = 0 then
                begin
                        dem := dem + 1;
                        tong := tong + a[i];
                end;
        writeln('Co ', dem,' gia tri am, tong la: ', tong);
        // Cau c:
        vt := 1;
        for i := 2 to n do
                if a[i] > a[vt] then vt := i;
        writeln('Vi tri phan tu lon nhat: ', vt);
end.
