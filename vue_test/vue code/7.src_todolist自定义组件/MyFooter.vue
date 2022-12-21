<template>
    <div class="todo-footer" v-show="total > 0">
        <label>
            <!-- 全选的第一种做法 -->
            <!-- <input type="checkbox" :checked="isAll" @change="checkAll" /> -->
            <!-- 全选的第二种做法 -->
            <input type="checkbox" v-model="isAll" />
        </label>
        <span>
            <span>已完成{{doneTotal}}</span>  /  全部 {{total}}
        </span>
        <button class="btn btn-danger" @click="clearAll">清楚已完成任务</button>
    </div>
  </template>
   
  <script>
  export default {
      name:'MyFooter',
      props:['todos'],
      computed:{
          total(){
              return this.todos.length
          },
          doneTotal(){
              // 老师写的第一种土方法
              /* let i =0
              this.todos.forEach((todo) => {
                  if(todo.done) i++
              });
              return i */
   
              // 高端方法
              /* const x = this.todos.reduce((pre,current)=>{
                  console.log('@',pre,current)
                  return pre + (current.done ? 1 : 0)
              },0) */
              return this.todos.reduce((pre,todo)=> pre + (todo.done ? 1 : 0) ,0)
          },
          isAll:{
              get(){
                  return this.doneTotal === this.total && this.total > 0
              },
              // 全选的第二种做法
              set(value){
                  this.$emit('checkAllTodo',value)
              }
          }
      },
      methods: {
          // 全选的第一种做法
          /* checkAll(e){
              this.checkAllTodo(e.target.checked)
          } */
          clearAll(){
              this.$emit('clearAllTodo',)
          }
      },
   
  }
  </script>
   
  <style scoped>
  /* footer */
  .todo-footer {
      height: 40px;
      line-height: 40px;
      padding-left: 6px;
      margin-top: 5px;
  }
  .todo-footer label {
      display: inline-block;
      margin-right: 20px;
      cursor: pointer;
  }
  .todo-footer label input{
      position: relative;
      top: -1px;
      vertical-align: middle;
      margin-right: 5px;
  }
  .todo-footer button{
      float: right;
      margin-top: 5px;
  }
  </style>