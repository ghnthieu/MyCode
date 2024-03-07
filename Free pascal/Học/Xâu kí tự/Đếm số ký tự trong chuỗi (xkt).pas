Program demkt;
uses crt;
var s:string;
    n,i,dem:integer;
begin
  clrscr;
  dem:=0;
  write('Nhap ky tu muon dem: ');readln(s);
  writeln('Nhap 1 de tinh so, 2 de tinh chu, 3 de tinh chuoi');
  write('Ban hay nhap: ');readln(n);
  case n of
    1:begin
        for i:=1 to length(s) do
          if s[i] in['0'..'9'] then
            inc(dem);
        writeln('So chu so duoc nhap la: ',dem);
      end;
    2:begin
        for i:=1 to length(s) do
          begin
            if s[i] in['a'..'z'] then
              inc(dem);
            if s[i] in['A'..'Z'] then
              inc(dem);
          end;
        writeln('So chu cai trong chuoi la: ',dem);
      end;
    3:write('So chuoi da nhap la: ',length(s));
  end;
  readln
End.