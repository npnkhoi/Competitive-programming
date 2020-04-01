uses crt;
var s: string;
begin
        readln(s);
        writeln('So ki tu: ', length(s));
        while (pos('dihoc', s) <> 0) do
        begin
                insert('lam', s, pos('dihoc', s));
                delete(s, pos('dihoc', s), 3);
        end;
        writeln(s);
end.
