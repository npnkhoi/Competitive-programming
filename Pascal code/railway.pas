uses crt;
var s:string;
n,a,b,c,j,i:integer;
begin
read(n);read(a);readln(b);readln(s);
if b>a then begin j:=b;b:=a;a:=j;end;
if (a=0) or (b=0) then begin writeln(1);exit;end;
for i:=1 to length(s) do
        begin
        if (s[i]='.') then
                begin
                if (c mod 2 =0) and (a>0) then begin dec(a);inc(c);continue;end;
                if (c mod 2=1) and (b>0) then begin dec(b);inc(c);continue;end;
                end;
        end;
writeln(c);
readkey;
end.