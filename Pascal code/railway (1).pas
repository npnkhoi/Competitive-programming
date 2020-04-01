uses crt;
var s:string;
n,a,b,c,j,i:integer;consecutive:boolean;
begin
read(n);read(a);readln(b);readln(s);
consecutive:=true;
if b>a then begin j:=b;b:=a;a:=j;end;j:=0;
for i:=1 to length(s) do
        begin
        if (s[i]='.') then
                begin
                if consecutive=false then begin if b>a then begin j:=b;b:=a;a:=j;end;j:=0;end;
                if (consecutive=false) and(a>0) then begin dec(a);inc(j);inc(C);continue;end;
                if consecutive then
                        begin
                                if s[i]<>s[i+1] then begin consecutive:=false;end else consecutive:=true;
                                if (j mod 2=1) and (b>0) then begin dec(b);inc(j);inc(c);continue;end;
                                if (j mod 2=0) and (a>0) then begin dec(a);inc(j);inc(c);continue;end;
                        end;

                end;

        end;
writeln(c);
readkey;
end.