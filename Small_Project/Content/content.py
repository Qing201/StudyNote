import PyPDF2
import sys

class PdfDirGenerator:

    def __init__(self, pdf_path:str, txt_path:str, offset:int, out_path:str=None, levelmark:str='.'):
        
        self.pdf_path = pdf_path    # pdf路径
        self.txt_path = txt_path    # 包含pdf目录信息的txt
        self.offset = offset        # 目录页数偏移量
        self.out_path = out_path    # 输出路径
        self.levelmark = levelmark  # 用于判断书签级别的标志符
    
          
        self.dir_parent = [None]    

    def getLevelId(self, level):
        """计算书签的级数（级数的标志符号为“.”）
        一级目录: 0 个“.”，例如: 第1章、附录A等
            二级目录: 1个“.”，例如: 1.1、A.1
                三级目录: 2个“.”，例如: 2.1.3
        """
        mark_num = 0
        for c in level:
            if c == self.levelmark:
                mark_num += 1
        return mark_num + 1

    def run(self):
        
        print("--------------------------- Adding the bookmark ---------------------------")
        print(" * PDF Source: %s" % self.pdf_path)
        print(" * TXT Source: %s" % self.txt_path)
        print(" * Offset: %d" % self.offset)
        print("---------------------------------------------------------------------------")
        with open(self.txt_path, 'r', encoding='utf-8') as txt:
            
            pdf_reader = PyPDF2.PdfReader(self.pdf_path)
            pdf_writer = PyPDF2.PdfWriter()
            
            pdf_writer.clone_document_from_reader(pdf_reader)
            # BUG: ValueError: {’/Type’: ‘/Outlines’, ‘/Count’: 0} is not in list
            # 修改代码 ${PYTHON_PATH}/site-packages/PyPDF2/pdf.py): getOutlineRoot 函数
            # 参考：https://www.codetd.com/en/article/11823498

            lines = txt.readlines()
            num_all_lines = len(lines)
            for i, line in enumerate(lines):
                # pline = line.split(' ') # 要求level title page之间只能有一个空格且不能是\t, 比较麻烦换成下面这个
                pline = line.split(None, maxsplit=-1) # python 3.6.13, 支持删除\t\n 空格, 且不限次数
                if len(pline) == 2:
                    level = pline[0]; title = ""; page = int(pline[1]) + self.offset
                elif len(pline) == 3:
                    level = pline[0]; title = pline[1]; page = int(pline[2]) + self.offset
                else:       # 英文中包含空格
                    level = pline[0]; title = ' '.join(pline[1:len(pline)-1]); page = int(pline[len(pline)-1]) + self.offset

                # 1. 计算当前的 level 的级数 id
                # 2. 当前书签的父结点存放在 dir_parent[id-1] 上
                # 3. 更新/插入 dir_parent[id] 
                id = self.getLevelId(level)
                if id >= len(self.dir_parent):
                    self.dir_parent.append(None)
                self.dir_parent[id] = pdf_writer.add_outline_item(level+' '+title, page-1, self.dir_parent[id-1])
                
                print(" * [%d/%d finished] level: %s(%d), title: %s, page: %d" % (i+1, num_all_lines, level, id, title, page))
            
            if self.out_path is None:
                self.out_path = self.pdf_path[:-4] + '(书签).pdf'
            with open(self.out_path, 'wb') as out_pdf:
                pdf_writer.write(out_pdf)
                print("---------------------------------------------------------------------------")
                print(" * Save: %s" % self.out_path)
                print("---------------------------------- Done! ----------------------------------")

if __name__ == '__main__':
    
    input_num = len(sys.argv)
    assert(input_num > 3)
    
    opath = None
    if input_num > 4:
        opath = sys.argv[4]

    mark='.'
    if input_num > 5:
        mark = sys.argv[5]

    pdg = PdfDirGenerator(
        pdf_path=sys.argv[1],
        txt_path=sys.argv[2],
        offset=int(sys.argv[3]), # 一般是目录结束页的页数
        out_path=opath,
        levelmark=mark
    )

    pdg.run()

