Program demkt;
uses crt;
var s:string;
    i:integer;
    ch:char;
    dem:array['A'..'Z'] of byte;
begin
  clrscr;
  write('Nhap ky tu muon dem: ');readln(s);
  for i:=1 to length(s) do
    s[i]:=upcase(s[i]);
  fillchar(dem,sizeof(dem),0);
  for i:=1 to length(s) do
    if s[i] in['A'..'Z'] then
      inc(dem[s[i]]);
  for ch:='A' to 'Z' do
    if dem[ch]<>0 then
      writeln(ch,' xuat hien ',dem[ch],' lan');
  readln
End.