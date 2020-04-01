//USES CRT;
var s:ansistring;
    loop,t,i,n:longint;
    ok:boolean;
begin
    readln(t);
    for loop:= 1 to t do
    begin
        readln(s);
        s:= 'C'+s+'C';
        n:= length(s);
        ok:= true;
        for i:= 2 to n-1 do if s[i]='B' then
        begin
            if s[i-1]='A' then s[i-1]:= 'C'
            else if s[i+1]='A' then s[i+1]:= 'C'
                else
                begin
                    writeln('NO');
                    ok:= false;
                    break;
                end;
        end;
        if ok then writeln('YES');
    end;
end.