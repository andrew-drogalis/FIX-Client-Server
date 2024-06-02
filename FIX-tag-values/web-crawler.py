import json
from re import split
from bs4 import BeautifulSoup
import requests

def save_json_file(name, data_dictionary):
    """
    Args:
        name (): A string for the name / path of the json file 
        data_dictionary (): A python dictionary to be converted to JSON 
    """
    with open(name, "w", encoding = "UTF-8") as json_file:
        json.dump(data_dictionary, json_file, indent = 4)

def request_url_html(url):
    """
    Args:
        url (): The url to fetch html document 

    Returns: The html document
    """
    response = requests.get(url)
    return response.text

def process_html_and_save(name, html, processing_function):
    """
    Args:
        name (): A string for the name / path of the json file
        html (): The html document to parse
        processing_function (): A function to process the specific html doc
    """
    parser = BeautifulSoup(html, "html.parser")
    results_dictionary = processing_function(parser)
    save_json_file(name, results_dictionary)

def process_btobits_url_fields_tag(parser):
    """
    Custom HTML Parse for https://btobits.com/fixopaedia/fixdic44/fields_by_tag_.html
    Args:
        parser (): A BeautifulSoup parser with the html loaded

    Returns: A dictionary with the message key and message name 
    """
    results_dictionary = {}
    string = parser.body.select_one("table:nth-of-type(2)").text
    split_string = string.split("\n")
    for substr in split_string:
        if substr.find("\xa0") != -1:
            line_split = substr.split("\xa0")
            if line_split[0][0] == "(":
                results_dictionary.update({line_split[0][1:-1]: line_split[1]})

    return results_dictionary

def process_btobits_url_message_types(parser):
    """
    Custom HTML Parse for https://btobits.com/fixopaedia/fixdic44/tag_35_MsgType_.html
    Args:
        parser (): A BeautifulSoup parser with the html loaded

    Returns: A dictionary with the message key and message name 
    """
    results_dictionary = {}
    string = parser.body.select_one("p:nth-of-type(3)").text
    split_string = string.split("\n")
    for substr in split_string:
        if substr.find("\xa0") != -1:
            line_split = substr.split("\xa0")
            results_dictionary.update({line_split[1][1:-1]: line_split[0]})

    return results_dictionary


def main():
    fix_reference_url = "https://btobits.com/fixopaedia/fixdic44/fields_by_tag_.html"
    fix_message_type_url = "https://btobits.com/fixopaedia/fixdic44/tag_35_MsgType_.html"
    json_name_field_tags = "FIX-tag-values/FIX-44-field-tags.json"
    json_name_message_types = "FIX-tag-values/FIX-44-message-types.json"

    process_html_and_save(json_name_field_tags,
                          request_url_html(fix_reference_url), process_btobits_url_fields_tag)
    process_html_and_save(json_name_message_types,
                          request_url_html(fix_message_type_url), process_btobits_url_message_types)


if __name__ == "__main__":
    main()
