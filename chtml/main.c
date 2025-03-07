#include <stdio.h>
#include <stdlib.h>

#include "html_tags.h"

typedef struct {
  char *user_name;
  int task_count;
  char **tasks;
} user_tasks;

void user_tasks_html(FILE *fp, user_tasks *data) {
  {
    DOCTYPE;
    HTML("en") {
      HEAD() {
        META("charset='utf-8'");
        META("name='viewport' "
             "content='width=device-width, initial-scale=1'");
        TITLE("Index page");
        META("name='description' content='Description'");
        META("name='author' content='Author'");
        META("property='og:title' content='Title'");
        LINK("rel='icon' href='/favicon.svg' type='image/svg+xml'");
        LINK("rel='stylesheet' href='css/styles.css'");
      }
      BODY("") {
        DIV("id='main'") {
          H1("id='title'") { _("Hello %s", data->user_name); }
          if (data->task_count > 0) {
            UL("class='default'") {
              for (int i = 0; i < data->task_count; i++) {
                LI("class='default'") {
                  _("Task %d: %s", i + 1, data->tasks[i]);
                }
              }
            }
          }
        }
      }
      SCRIPT("js/main.js");
    }
  }
}

int main(void) {
  user_tasks data;
  {
    data.user_name = "John";
    data.task_count = 3;
    data.tasks = calloc(data.task_count, sizeof(char *));
    {
      data.tasks[0] = "Feed the cat";
      data.tasks[1] = "Clean the room";
      data.tasks[2] = "Go to the gym";
    }
  }
  char *html;
  size_t html_size;
  FILE *fp;
  fp = open_memstream(&html, &html_size);
  if (fp == NULL) {
    return 1;
  }
  user_tasks_html(fp, &data);
  fclose(fp);
  printf("%s\n", html);
  printf("%lu bytes\n", html_size);
  free(html);
  free(data.tasks);
  return 0;
}
