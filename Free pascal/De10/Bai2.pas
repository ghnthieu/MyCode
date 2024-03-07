Program sgnt;
uses crt;
function snt(n:integer):boolean;
var i:integer;
begin
  if n<2 then
    exit(false);
  for i:=2 to trunc(sqrt(n)) do
    if n mod i=0 then
      exit(false);
  exit(true);
end;
procedure xuly;
var fi,fo:text;
    s:ansistring;
    t,i:byte;
    tong:longint;
    ok:boolean;
    n:real;
begin
  assign(fi,'Giant.inp');reset(fi);
  assign(fo,'Giant.out');rewrite(fo);
  read(fi,n);
  str(n,s);
  tong:=0;
  ok:=true;
  for i:=1 to length(s) do
    begin
      if s[i] in ['0'..'9'] then
        begin
          val(s[i],t);
          if not(snt(t)) then
            begin
              ok:=false;
              break;
            end
          else
            tong:=tong+t;
        end;
    end;
  if (snt(tong)) and (ok) then
    write(fo,'CO')
  else
    write(fo,'KHONG');
  close(fi);
  close(fo);
end;
Begin
  xuly;
End.
