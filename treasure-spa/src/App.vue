<template>
  <v-app>
    <v-app-bar app color="primary" dark>
      <div class="d-flex align-center">
        <v-img
          alt="Vuetify Logo"
          class="shrink mr-2"
          contain
          src="https://cdn.vuetifyjs.com/images/logos/vuetify-logo-dark.png"
          transition="scale-transition"
          width="40"
        />

        <v-img
          alt="Vuetify Name"
          class="shrink mt-1 hidden-sm-and-down"
          contain
          min-width="100"
          src="https://cdn.vuetifyjs.com/images/logos/vuetify-name-dark.png"
          width="100"
        />
      </div>

      <v-spacer></v-spacer>

      <v-btn v-on:click="sendMessage(message)">Click here</v-btn>
      <v-btn v-on:click="getStatusBuzzer(getBuzzerJSON)">BuzzerStatus</v-btn>
    </v-app-bar>

    <v-main>
      <v-card>Message: {{ this.message }}</v-card>
      <v-card>Buzzer: {{ statusBuzzer }}</v-card>
    </v-main>
  </v-app>
</template>

<script lang="ts">
import Vue from "vue";

export default Vue.extend({
  name: "App",

  components: {},
  methods: {
    sendMessage: function(message: string) {
      //console.log(JSON.stringify(message))
      console.log(this.connection);
      if (message != null) {
        this.connection.send(JSON.stringify(this.message));
      }
    },
    getStatusBuzzer: function(getBuzzerJSON) {
      this.statusBuzzer = this.connection.send(JSON.stringify(this.getBuzzerJSON))

    }
  },
  data: function() {
    return {
      connection: null,
      message: {
        // eslint-disable-next-line prettier/prettier
        "setVars": {
        // eslint-disable-next-line prettier/prettier
        "isBuzzerHit": true
        }
      },
      getBuzzerJSON: { "getVars": true},
      statusBuzzer: {}
    };
  },
  created: function() {
    console.log("Starting WebSocket Connection.");
    this.connection = new WebSocket("ws://192.168.137.62:81");

    this.connection.onopen = function(event) {
      console.log(event);
      console.log("Successfull connected.");
    };

    this.connection.onmessage = function(event) {
      console.log(event);
      this.statusBuzzer = JSON.parse(event.data)
    };
  }
  //
});
</script>
