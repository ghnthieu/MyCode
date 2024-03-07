Program bai3;
uses crt;
var s:string;
procedure nhap(var s:string);
begin
  write('Nhap xau: ');readln(s);
end;
procedure xuly(s:string);
var i,dem:byte;
begin
  dem:=0;
  for i:=1 to length(s) do
    if s[i] in ['0'..'9'] then
      inc(dem);
  write('Trong xau ',s,' co: ',dem,' ky tu so');
end;
Begin
  clrscr;
  nhap(s);
  xuly(s);
  readln
End.