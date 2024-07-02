import scrapy
import os
from scrapy.http import FormRequest
import html2text
from parsel import Selector
from scrapy.selector import Selector

class ClaojspiderSpider(scrapy.Spider):
    def __init__(self):
        self.pgcnt=0
    name = 'claojspider'
    allowed_domains = ['claoj.edu.vn']
    start_urls = ['https://claoj.edu.vn/accounts/login/']
    custom_settings = {
            "REQUEST_FINGERPRINTER_IMPLEMENTATION": "2.7"
        }

    def parse(self, response):

        token = response.css("form input[name=csrfmiddlewaretoken]::attr(value)").get()
        print('-======================-')
        print(token)
        print('-======================-')
        return FormRequest.from_response(
            response,
            formdata={
                'csrfmiddlewaretoken': token, 
                'password': 'password',
                'username': 'username'
            },
            callback=self.start_scraping
        )

    def start_scraping(self, response):
        url = 'https://claoj.edu.vn/submissions/user/lds/?status=AC'
        yield scrapy.Request(url, callback=self.parsing)

    def parsing(self, response):
        if  self.pgcnt == 22:
            return
        self.pgcnt+=1
        submissions = response.css('.submission-row')
        for submission in submissions:
            relative_url = submission.css('.sub-prop a ::attr(href)').get()
            sub_url = 'https://claoj.edu.vn' + relative_url
            yield scrapy.Request(sub_url, callback=self.parse_sub_page, priority=1)

        next_url = 'https://claoj.edu.vn/submissions/user/lds/' + str(self.pgcnt)+'?status=AC'
        yield scrapy.Request(next_url, callback=self.parsing)

    
    def parse_sub_page(self,response):
        code_content = response.css('code').get()
        code_text = Selector(text=code_content).xpath('string()').get()
        
        prob_id = response.xpath('//*[@id="content"]/h2/a[1]/@href').extract()
        prob_id = str(prob_id[0])[9:]
        print(prob_id)
        code = str(code_text)
        path = 'code/'+ prob_id +".cpp"
        with open(path, 'w') as file: 
            file.write(code) 
     
