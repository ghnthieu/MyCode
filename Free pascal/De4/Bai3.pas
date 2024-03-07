Program bai3;
uses crt;
var fi,fo:text;
    s:string;
procedure xuly;
var i,dem,t:byte;
    tong:integer;
    fi,fo:text;
    a:string;
begin
  assign(fi,'xau.inp');reset(fi);
  assign(fo,'xau.out');rewrite(fo);
  read(fi,s);
  tong:=0;
  dem:=0;
  a:='';
  for i:=1 to length(s) do
    if s[i] in ['0'..'9'] then
      begin
        inc(dem);
        val(s[i],t);
        tong:=tong+t;
      end
    else
      a:=a+s[i];
  writeln(fo,dem);
  writeln(fo,tong);
  writeln(fo,a);
  close(fi);
  close(fo);
end;
Begin
  xuly;
End.
