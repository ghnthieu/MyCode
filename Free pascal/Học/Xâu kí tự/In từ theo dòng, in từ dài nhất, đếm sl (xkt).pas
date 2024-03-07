`Program lt_ct_td_dtd;
uses crt;
var s:string;
    i,k,max:integer;
    dem:byte;
    a:array[1..100] of string;
begin
  clrscr;
  write('Nhap xau ky tu: ');readln(s);
  k:=1;
  i:=1;
  while i<=length(s) do
    begin
      if s[i]=#32 then
        begin
          inc(i);
          inc(k);
        end;
      a[k]:=a[k]+s[i];
      inc(i);
    end;
  writeln('Ki tu duoc in theo hang la');
  for i:=1 to k do
    writeln(a[i]);
  max:=length(a[1]);
  for i:=2 to k do
    if max<length(a[i]) then
      max:=length(a[i]);
  dem:=0;
  write('Chu co nhieu ki tu nhat la: ');
  for i:=1 to k do
    if length(a[i])=max then
      begin
        inc(dem);
        write(a[i],' ');
      end;
  writeln;
  writeln('Co ',dem,' chu co nhieu ki tu nhat');
  readln
End.
